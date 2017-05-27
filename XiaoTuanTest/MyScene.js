
import React , { Component , PropTypes } from 'react' ;
import { View , Text , TouchableNativeFeedback } from 'react-native' ;

export default class MyScene extends Component
{
    static propTypes =
    {
        title: PropTypes.string.isRequired ,
        onForward : PropTypes.func.isRequired ,
        onBack : PropTypes.func.isRequired ,
        onLongPressTip : PropTypes.func.isRequired ,
    }
    
    render ()
    {
        return (
            <View style = {{ top:20}}>
                <Text> Current Scene : {this.props.title} </Text>
                <TouchableNativeFeedback onPress = { this.props.onForward }>
                    <Text>点我进入下一场景</Text>
                </TouchableNativeFeedback>
                
                <TouchableNativeFeedback onPress = { this.props.onBack }>
                <Text>点我返回上一场景</Text>
                </TouchableNativeFeedback>

                <TouchableNativeFeedback onLongPress = { this.props.onLongPressTip }>
                <Text>长按</Text>
                </TouchableNativeFeedback>

            </View>
                )
    }
}
