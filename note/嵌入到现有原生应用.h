嵌入到现有原生应用
在GitHub上修改这篇文档
支持我们
平台: Objective-C Swift Android

核心概念
如果你正准备从头开始制作一个新的应用，那么React Native会是个非常好的选择。但如果你只想给现有的原生应用中添加一两个视图或是业务流程，React Native也同样不在话下。只需简单几步，你就可以给原有应用加上新的基于React Native的特性、画面和视图等。

把React Native组件植入到iOS应用中有如下几个主要步骤：

首先当然要了解你要植入的React Native组件。
创建一个Podfile，在其中以subspec的形式填写所有你要植入的React Native的组件。
创建js文件，编写React Native组件的js代码。
添加一个事件处理函数，用于创建一个RCTRootView。这个RCTRootView正是用来承载你的React Native组件的，而且它必须对应你在index.ios.js中使用AppRegistry注册的模块名字。
启动React Native的Packager服务，运行应用。
根据需要添加更多React Native的组件。
调试。
准备部署发布 （比如可以利用react-native-xcode.sh脚本）。
发布应用，升职加薪，走向人生巅峰！😘
开发环境准备
基础环境
首先按照开发环境搭建教程来安装React Native在iOS平台上所需的一切依赖软件（比如npm）。

CocoaPods
CocoaPods是针对iOS和Mac开发的包管理工具。我们用它来把React Native框架的代码下载下来并添加到你当前的项目中。

$ sudo gem install cocoapods
从技术上来讲，我们完全可以跳过CocoaPods，但是这样一来我们就需要手工来完成很多配置项。CocoaPods可以帮我们完成这些繁琐的工作。
示例App
在本教程中我们用于示范的app是一个2048类型的游戏。 下面是这个游戏还没有植入React Native时的主界面：

Before RN Integration

依赖包
React Native的植入过程同时需要React和React Native两个node依赖包。

package.json
我们把具体的依赖包记录在package.json文件中。如果项目根目录中没有这个文件，那就自己创建一个。

对于一个典型的React Native项目来说，一般package.json和index.ios.js等文件会放在项目的根目录下。而iOS相关的原生代码会放在一个名为ios/的子目录中,这里也同时放着你的Xcode项目文件（.xcodeproj）。
下面是一个最简单的package.json的内容示例。

示例中的version字段没有太大意义（除非你要把你的项目发布到npm仓库）。scripts中是用于启动packager服务的命令。dependencies中的react和react-native的版本取决于你的具体需求。一般来说我们推荐使用最新版本。你可以使用npm info react和npm info react-native来查看当前的最新版本。另外，react-native对react的版本有严格要求，高于或低于某个范围都不可以。本文无法在这里列出所有react native和对应的react版本要求，只能提醒读者先尝试执行npm install，然后注意观察安装过程中的报错信息，例如require react@某.某.某版本, but none was installed，然后根据这样的提示，执行npm i -S react@某.某.某版本。
{
    "name": "NumberTileGame",
    "version": "0.0.1",
    "private": true,
    "scripts": {
        "start": "node node_modules/react-native/local-cli/cli.js start"
    },
    "dependencies": {
        "react": "15.4.1",
        "react-native": "0.39.2"
    }
}
安装依赖包
使用npm（node包管理器，Node package manager）来安装React和React Native模块。这些模块会被安装到项目根目录下的node_modules/目录中。 在包含有package.json文件的目录（一般也就是项目根目录）中运行下列命令来安装：

$ npm install
React Native框架
React Native框架整体是作为node模块安装到项目中的。下一步我们需要在CocoaPods的Podfile中指定我们所需要使用的组件。

Subspecs
在你开始把React Native植入到你的应用中之前，首先要决定具体整合的是React Native框架中的哪些部分。而这就是subspec要做的工作。在创建Podfile文件的时候，需要指定具体安装哪些React Native的依赖库。所指定的每一个库就称为一个subspec。

可用的subspec都列在node_modules/react-native/React.podspec中，基本都是按其功能命名的。一般来说你首先需要添加Core，这一subspec包含了必须的AppRegistry、StyleSheet、View以及其他的一些React Native核心库。如果你想使用React Native的Text库（即<Text>组件），那就需要添加RCTText的subspec。同理，Image需要加入RCTImage，等等。

Podfile

在React和React Native模块成功安装到node_modules目录之后，你就可以开始创建Podfile以便选择所需的组件安装到应用中。

创建Podfile的最简单的方式就是在iOS原生代码所在的目录中使用CocoaPods的init命令：

## 在iOS原生代码所在的目录中（也就是`.xcodeproj`文件所在的目录）执行：
$ pod init
Podfile会创建在执行命令的目录中。你需要调整其内容以满足你的植入需求。调整后的Podfile的内容看起来类似下面这样：

# target的名字一般与你的项目名字相同
target 'NumberTileGame' do

# 'node_modules'目录一般位于根目录中
# 但是如果你的结构不同，那你就要根据实际路径修改下面的`:path`
pod 'React', :path => '../node_modules/react-native', :subspecs => [
                                                                    'Core',
                                                                    'RCTText',
                                                                    'RCTNetwork',
                                                                    'RCTWebSocket', # 这个模块是用于调试功能的
# 在这里继续添加你所需要的模块
                                                                    ]

end
Pod安装

创建好了Podfile后，就可以开始安装React Native的pod包了。

$ pod install
然后你应该可以看到类似下面的输出(译注：同样由于众所周知的网络原因，pod install的过程在国内非常不顺利，请自行配备稳定的翻墙工具，或是尝试一些镜像源)：

Analyzing dependencies
Fetching podspec for `React` from `../node_modules/react-native`
Downloading dependencies
Installing React (0.26.0)
Generating Pods project
Integrating client project
Sending stats
Pod installation complete! There are 3 dependencies from the Podfile and 1 total pod installed.
代码集成
现在我们已经准备好了所有依赖，可以开始着手修改原生代码来把React Native真正植入到应用中了。在我们的2048示例中，首先尝试添加一个显示有"High Score"（得分排行榜）的React Native页面。

React Native组件
我们首先要写的是"High Score"（得分排行榜）的JavaScript端的代码。

创建一个index.ios.js文件

首先创建一个空的index.ios.js文件。一般来说我们把它放置在项目根目录下。

index.ios.js是React Native应用在iOS上的入口文件。而且它是不可或缺的！它可以是个很简单的文件，简单到可以只包含一行require/import导入语句。本教程中为了简单示范，把全部的代码都写到了index.ios.js里（当然实际开发中我们并不推荐这样做）。
# 在项目根目录执行以下命令创建文件：
$ touch index.ios.js
添加你自己的React Native代码

在index.ios.js中添加你自己的组件。这里我们只是简单的添加一个<Text>组件，然后用一个带有样式的<View>组件把它包起来。

'use strict';

import React from 'react';
import {
    AppRegistry,
    StyleSheet,
    Text,
    View
} from 'react-native';

class RNHighScores extends React.Component {
    render() {
        var contents = this.props["scores"].map(
                                                score => <Text key={score.name}>{score.name}:{score.value}{"\n"}</Text>
                                                );
        return (
                <View style={styles.container}>
                <Text style={styles.highScoresTitle}>
                2048 High Scores!
                </Text>
                <Text style={styles.scores}>
                {contents}
                </Text>
                </View>
                );
    }
}

const styles = StyleSheet.create({
container: {
flex: 1,
justifyContent: 'center',
alignItems: 'center',
backgroundColor: '#FFFFFF',
},
highScoresTitle: {
fontSize: 20,
textAlign: 'center',
margin: 10,
},
scores: {
textAlign: 'center',
color: '#333333',
marginBottom: 5,
},
});

// 整体js模块的名称
AppRegistry.registerComponent('RNHighScores', () => RNHighScores);
RNHighScores是整体js模块（即你所有的js代码）的名称。你在iOS原生代码中添加React Native视图时会用到这个名称。
The Magic: RCTRootView
现在我们已经在index.ios.js中创建了React Native组件，下一步就是把这个组件添加给一个新的或已有的ViewController。 The easiest path to take is to optionally create an event path to your component and then add that component to an existing ViewController.

We will tie our React Native component with a new native view in the ViewController that will actually host it called RCTRootView .

Create an Event Path
You can add a new link on the main game menu to go to the "High Score" React Native page.

Event Path

事件处理

We will now add an event handler from the menu link. A method will be added to the main ViewController of your application. This is where RCTRootView comes into play.

When you build a React Native application, you use the React Native packager to create an index.ios.bundle that will be served by the React Native server. Inside index.ios.bundle will be our RNHighScore module. So, we need to point our RCTRootView to the location of the index.ios.bundle resource (via NSURL) and tie it to the module.

We will, for debugging purposes, log that the event handler was invoked. Then, we will create a string with the location of our React Native code that exists inside the index.ios.bundle. Finally, we will create the main RCTRootView. Notice how we provide RNHighScores as the moduleName that we created above when writing the code for our React Native component.

首先导入RCTRootView的头文件。

#import "RCTRootView.h"
这里的initialProperties are here for illustration purposes so we have some data for our high score screen. In our React Native component, we will use this.props to get access to that data.
- (IBAction)highScoreButtonPressed:(id)sender {
    NSLog(@"High Score Button Pressed");
    NSURL *jsCodeLocation = [NSURL
                             URLWithString:@"http://localhost:8081/index.ios.bundle?platform=ios"];
    RCTRootView *rootView =
    [[RCTRootView alloc] initWithBundleURL : jsCodeLocation
                         moduleName        : @"RNHighScores"
                         initialProperties :
     @{
       @"scores" : @[
               @{
                   @"name" : @"Alex",
                   @"value": @"42"
                   },
               @{
                   @"name" : @"Joel",
                   @"value": @"10"
                   }
               ]
       }
                          launchOptions    : nil];
    UIViewController *vc = [[UIViewController alloc] init];
    vc.view = rootView;
    [self presentViewController:vc animated:YES completion:nil];
}
Note that RCTRootView initWithURL starts up a new JSC VM. To save resources and simplify the communication between RN views in different parts of your native app, you can have multiple views powered by React Native that are associated with a single JS runtime. To do that, instead of using [RCTRootView alloc] initWithURL, use RCTBridge initWithBundleURL to create a bridge and then use RCTRootView initWithBridge.
When moving your app to production, the NSURL can point to a pre-bundled file on disk via something like [[NSBundle mainBundle] URLForResource:@"main" withExtension:@"jsbundle"];. You can use the react-native-xcode.sh script in node_modules/react-native/packager/ to generate that pre-bundled file.
Wire Up

Wire up the new link in the main menu to the newly added event handler method.

Event Path

One of the easier ways to do this is to open the view in the storyboard and right click on the new link. Select something such as the Touch Up Inside event, drag that to the storyboard and then select the created method from the list provided.
测试植入结果
You have now done all the basic steps to integrate React Native with your current application. Now we will start the React Native packager to build the index.ios.bundle packager and the server running on localhost to serve it.

App Transport Security
Apple has blocked implicit cleartext HTTP resource loading. So we need to add the following our project's Info.plist (or equivalent) file.

<key>NSAppTransportSecurity</key>
<dict>
<key>NSExceptionDomains</key>
<dict>
<key>localhost</key>
<dict>
<key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
<true/>
</dict>
</dict>
</dict>
运行Packager
# From the root of your project, where the `node_modules` directory is located.
$ npm start
运行应用
如果你使用的是Xcode，那么照常编译和运行应用即可。如果你没有使用Xcode（但是你仍然必须安装Xcode），则可以在命令行中使用以下命令来运行应用：

# 在项目的根目录中执行：
$ react-native run-ios
In our sample application, you should see the link to the "High Scores" and then when you click on that you will see the rendering of your React Native component.

Here is the native application home screen:

Home Screen

Here is the React Native high score screen:

High Scores

If you are getting module resolution issues when running your application please see this GitHub issue for information and possible resolution. This comment seemed to be the latest possible resolution.
看一下完整的代码变更
你可以在这个GitHub提交记录里查看一次完整的植入过程具体有哪些代码/文件变更。
