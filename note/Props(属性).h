#pragma mark - Props（属性）

大多数组件在创建时就可以使用各种参数来进行定制。用于定制的这些参数就称为props（属性）。

以常见的基础组件Image为例，在创建一个图片时，可以传入一个名为source的prop来指定要显示的图片的地址，以及使用名为style的prop来控制其尺寸。

import React, { Component } from 'react';
import { AppRegistry, Image } from 'react-native';

class Bananas extends Component {
    render() {
        let pic = {
        uri: 'https://upload.wikimedia.org/wikipedia/commons/d/de/Bananavarieties.jpg'
        };
        return (
                <Image source={pic} style={{width: 193, height: 110}} />
                );
    }
}

AppRegistry.registerComponent('Bananas', () => Bananas);
译注：在iOS上使用http链接的图片地址可能不会显示，参见这篇说明修改。

请注意{pic}外围有一层括号，我们需要用括号来把pic这个变量嵌入到JSX语句中。括号的意思是括号内部为一个js变量或表达式，需要执行后取值。因此我们可以把任意合法的JavaScript表达式通过括号嵌入到JSX语句中。

自定义的组件也可以使用props。通过在不同的场景使用不同的属性定制，可以尽量提高自定义组件的复用范畴。只需在render函数中引用this.props，然后按需处理即可。下面是一个例子：

import React, { Component } from 'react';
import { AppRegistry, Text, View } from 'react-native';

class Greeting extends Component {
    render() {
        return (
                <Text>Hello {this.props.name}!</Text>
                );
    }
}

class LotsOfGreetings extends Component {
    render() {
        return (
                <View style={{alignItems: 'center'}}>
                <Greeting name='Rexxar' />
                <Greeting name='Jaina' />
                <Greeting name='Valeera' />
                </View>
                );
    }
}

AppRegistry.registerComponent('LotsOfGreetings', () => LotsOfGreetings);
我们在Greeting组件中将name作为一个属性来定制，这样可以复用这一组件来制作各种不同的“问候语”。上面的例子把Greeting组件写在JSX语句中，用法和内置组件并无二致——这正是React体系的魅力所在——如果你想搭建一套自己的基础UI框架，那就放手做吧！

上面的例子出现了一样新的名为View的组件。View 常用作其他组件的容器，来帮助控制布局和样式。

仅仅使用props和基础的Text、Image以及View组件，你就已经足以编写各式各样的UI组件了。要学习如何动态修改你的界面，那就需要进一步学习State（状态）的概念。
