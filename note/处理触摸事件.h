处理触摸事件


移动应用上的用户交互基本靠“摸”。当然，“摸”也是有各种姿势的：在一个按钮上点击，在一个列表上滑动，或是在一个地图上缩放。

React Native提供了可以处理常见触摸手势（例如点击或滑动）的组件， 以及可用于识别更复杂的手势的完整的手势响应系统。

可点击的组件
在需要捕捉用户点击操作时，可以使用"Touchable"开头的一系列组件。这些组件通过onPress属性接受一个点击事件的处理函数。当一个点击操作开始并且终止于本组件时（即在本组件上按下手指并且抬起手指时也没有移开到组件外），此函数会被调用。

示例：

class MyButton extends Component {
    _onPressButton() {
        console.log("You tapped the button!");
    }
    
    render() {
        return (
                <TouchableHighlight onPress={this._onPressButton}>
                <Text>Button</Text>
                </TouchableHighlight>
                );
    }
}
可点击的组件需要给用户提供视觉反馈，例如是哪个组件正在响应用户的操作，以及当用户抬起手指后会发生什么。用户也应该可以通过把手指移到一边来取消点击操作。

具体使用哪种组件，取决于你希望给用户什么样的视觉反馈：

一般来说，你可以使用TouchableHighlight来制作按钮或者链接。注意此组件的背景会在用户手指按下时变暗。

在Android上还可以使用TouchableNativeFeedback，它会在用户手指按下时形成类似墨水涟漪的视觉效果。

TouchableOpacity会在用户手指按下时降低按钮的透明度，而不会改变背景的颜色。

如果你想在处理点击事件的同时不显示任何视觉反馈，则需要使用TouchableWithoutFeedback。

长按
某些场景中你可能需要检测用户是否进行了长按操作。可以在上面列出的任意组件中使用onLongPress属性来实现。

在列表中上下滑动和在视图上左右滑动
可滚动的列表是移动应用中一个常见的模式。用户会在列表中或快或慢的各种滑动。ScrollView组件可以满足这一需求。

ScrollView可以在垂直或水平方向滚动，还可以配置pagingEnabled属性来让用户整屏整屏的滑动。此外，水平方向的滑动还可以使用Android上的ViewPagerAndroid 组件。

ListView则是一种特殊的ScrollView，用于显示比较长的垂直列表。它还可以显示分区块的头部和尾部，类似iOS上的UITableView控件。

双指缩放
如果在ScrollView中只放置一个组件，则可以用来实现缩放操作。设置maximumZoomScale和minimumZoomScale属性即可以使用户能够缩放其中的内容。

处理其他的手势
如果你想实现视图的拖拽，或是实现自定义的手势，那么请参阅PanResponder API或是手势识别系统的文档
