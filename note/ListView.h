如何使用ListView

ListView组件用于显示一个垂直的滚动列表，其中的元素之间结构近似而仅数据不同。

ListView更适于长列表数据，且元素个数可以增删。和ScrollView不同的是，ListView并不立即渲染所有元素，而是优先渲染屏幕上可见的元素。

ListView组件必须的两个属性是dataSource和renderRow。dataSource是列表的数据源，而renderRow则逐个解析数据源中的数据，然后返回一个设定好格式的组件来渲染。

下面的例子创建了一个简单的ListView，并预设了一些模拟数据。首先是初始化ListView所需的dataSource，其中的每一项（行）数据之后都在renderRow中被渲染成了Text组件，最后构成整个ListView。

rowHasChanged函数也是ListView的必需属性。这里我们只是简单的比较两行数据是否是同一个数据（===符号只比较基本类型数据的值，和引用类型的地址）来判断某行数据是否变化了。
import React, { Component } from 'react';
import { AppRegistry, ListView, Text, View } from 'react-native';

class ListViewBasics extends Component {
    // 初始化模拟数据
    constructor(props) {
        super(props);
        const ds = new ListView.DataSource({rowHasChanged: (r1, r2) => r1 !== r2});
        this.state = {
        dataSource: ds.cloneWithRows([
                                      'John', 'Joel', 'James', 'Jimmy', 'Jackson', 'Jillian', 'Julie', 'Devin'
                                      ])
        };
    }
    render() {
        return (
                <View style={{flex: 1, paddingTop: 22}}>
                <ListView
                dataSource={this.state.dataSource}
                renderRow={(rowData) => <Text>{rowData}</Text>}
                />
                </View>
                );
    }
}

// 注册应用(registerComponent)后才能正确渲染
// 注意：只把应用作为一个整体注册一次，而不是每个组件/模块都注册
AppRegistry.registerComponent('ListViewBasics', () => ListViewBasics);
ListView的一个常用场景就是从服务器端取回列表数据然后显示，要实现这一过程，你可能还需要学习React Native的网络相关用法.
