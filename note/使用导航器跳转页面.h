使用导航器跳转页面

移动应用很少只包含一个页面。从你添加第二个页面开始，就得考虑如何管理多个页面间的跳转了。

导航器正是为此而生。它可以管理多个页面间的跳转，也包含了一些常见的过渡动画，包括水平翻页、垂直弹出等等。

Navigator
React Native目前有几个内置的导航器组件，一般来说我们首推Navigator。它使用纯JavaScript实现了一个导航栈，因此可以跨平台工作，同时也便于定制。



场景（Scene）的概念与使用
无论是View中包含Text，还是一个排满了图片的ScrollView，渲染各种组件现在对你来说应该已经得心应手了。这些摆放在一个屏幕中的组件，就共同构成了一个“场景（Scene）”。

场景简单来说其实就是一个全屏的React组件。与之相对的是单个的Text、Image又或者是你自定义的什么组件，仅仅占据页面中的一部分。你其实已经不知不觉地接触到了场景——在前面的教程中，“编写HelloWorld”、“使用Flexbox布局”、“如何使用ListView”中的组件都是完整的场景示例。

下面我们来定义一个仅显示一些文本的简单场景。创建一个名为“MyScene.js”的文件，然后粘贴如下代码：

import React, { Component } from 'react';
import { View, Text } from 'react-native';

export default class MyScene extends Component {
    static defaultProps = {
    title: 'MyScene'
    };
    
    render() {
        return (
                <View>
                <Text>Hi! My name is {this.props.title}.</Text>
                </View>
                )
    }
}
注意组件声明前面的export default关键字。它的意思是导出(export)当前组件，以允许其他组件引入(import)和使用当前组件，就像下面这样（下面的代码你可以写在index.ios.js或是index.android.js中）：

import React, { Component } from 'react';
import { AppRegistry } from 'react-native';

// ./MyScene表示的是当前目录下的MyScene.js文件，也就是我们刚刚创建的文件
// 注意即便当前文件和MyScene.js在同一个目录中，"./"两个符号也是不能省略的！
// 但是.js后缀是可以省略的

import MyScene from './MyScene';

class YoDawgApp extends Component {
    render() {
        return (
                <MyScene />
                )
    }
}

AppRegistry.registerComponent('YoDawgApp', () => YoDawgApp);
我们现在已经创建了只有单个场景的App。其中的MyScene同时也是一个可复用的React组件的例子。

使用Navigator
场景已经说的够多了，下面我们开始尝试导航跳转。首先要做的是渲染一个Navigator组件，然后通过此组件的renderScene属性方法来渲染其他场景。

render() {
    return (
            <Navigator
            initialRoute={{ title: 'My Initial Scene', index: 0 }}
            renderScene={(route, navigator) => {
        return <MyScene title={route.title} />
    }}
            />
            );
}
使用导航器经常会碰到“路由(route)”的概念。“路由”抽象自现实生活中的路牌，在RN中专指包含了场景信息的对象。renderScene方法是完全根据路由提供的信息来渲染场景的。你可以在路由中任意自定义参数以区分标记不同的场景，我们在这里仅仅使用title作为演示。

将场景推入导航栈

要过渡到新的场景，你需要了解push和pop方法。这两个方法由navigator对象提供，而这个对象就是上面的renderScene方法中传递的第二个参数。 我们使用这两个方法来把路由对象推入或弹出导航栈。

navigator.push({
title: 'Next Scene',
index: 1,
});

navigator.pop();
下面是一个更完整的示例：

import React, { Component } from 'react';
import { AppRegistry, Navigator, Text, View } from 'react-native';

import MyScene from './MyScene';

class SimpleNavigationApp extends Component {
    render() {
        return (
                <Navigator
                initialRoute={{ title: 'My Initial Scene', index: 0 }}
                renderScene={(route, navigator) =>
                    <MyScene
                    title={route.title}
                    
                    // Function to call when a new scene should be displayed
                    onForward={ () => {
                        const nextIndex = route.index + 1;
                        navigator.push({
                        title: 'Scene ' + nextIndex,
                        index: nextIndex,
                        });
                    }}
                    
                    // Function to call to go back to the previous scene
                    onBack={() => {
                        if (route.index > 0) {
                            navigator.pop();
                        }
                    }}
                    />
                }
                />
                )
    }
}

AppRegistry.registerComponent('SimpleNavigationApp', () => SimpleNavigationApp);
对应的MyScene.js代码如下：

import React, { Component, PropTypes } from 'react';
import { View, Text, TouchableHighlight } from 'react-native';

export default class MyScene extends Component {
    static propTypes = {
    title: PropTypes.string.isRequired,
    onForward: PropTypes.func.isRequired,
    onBack: PropTypes.func.isRequired,
    }
    render() {
        return (
                <View>
                <Text>Current Scene: { this.props.title }</Text>
                <TouchableHighlight onPress={this.props.onForward}>
                <Text>点我进入下一场景</Text>
                </TouchableHighlight>
                <TouchableHighlight onPress={this.props.onBack}>
                <Text>点我返回上一场景</Text>
                </TouchableHighlight>    
                </View>
                )
    }
    }
    在这个例子中，MyScene通过title属性接受了路由对象中的title值。它还包含了两个可点击的组件TouchableHighlight，会在点击时分别调用通过props传入的onForward和onBack方法，而这两个方法各自调用了navigator.push()和navigator.pop()，从而实现了场景的变化。
    
    查看Navigator API文档来了解更多Navigator的信息。同时推荐你阅读导航器对比和论坛中的一个详细教程来加深理解。
    
    恭喜！
    如果你一字不漏地看完了本教程，恭喜你获得成就：毅力+1！我们暂时没有更多的东西可以教你了，你可以看看一些社区的参考资源。
