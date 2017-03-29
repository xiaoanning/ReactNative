/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

//图片
//import React , { Component } from 'react' ;
//import { AppRegistry , Image } from 'react-native' ;

//class Bananas extends Component
//{
//    render ()
//    {
//        let pic = {
//            uri : 'https://upload.wikimedia.org/wikipedia/commons/d/de/Bananavarieties.jpg'
//        };
//        
//        return (
//                <Image source = {pic} style = { {width: 193 , height : 110 }} />
//        );
//    }
//}
//
//AppRegistry.registerComponent('XiaoTuanTest' , () => Bananas);


//自定义组件
//import React , { Component } from 'react' ;
//import { AppRegistry , View , Text } from 'react-native' ;
//
//class Greeting extends Component
//{
//    render ()
//    {
//        return (
//                <Text>Hello {this.props.name} ! </Text>
//        );
//    }
//}
//class LotsOfGreeting extends Component
//{
//    render()
//    {
//        return (
//                <View style = {{alignItems:'center'}}>
//                <Greeting name = '111' />
//                <Greeting name = '222' />
//                <Greeting name = '333' />
//                <Greeting  />
//
//                </View>
//        );
//    }
//}
//
//AppRegistry.registerComponent('XiaoTuanTest' , () => LotsOfGreeting);


//state  constructor()
//import React , { Component } from 'react' ;
//import { AppRegistry , Text , View } from 'react-native' ;
//
//class Blink extends Component
//{
//    constructor(props)
//    {
//        super(props);
//        this.state = { showText : true } ;
//        
//        setInterval(
//                    () => {
//                        this.setState({ showText : !this.state.showText});
//                    },
//                    100
//        );
//    }
//    
//    render(){
//           let display = this.state.showText ? this.props.text : ' ' ;
//           let displays = !this.state.showText ? this.props.text : ' ';
//
//           return (
////                   <Text > {display}</Text>
//                   <Text> {displays}</Text>
//
//           );
//    };
//}
//
//class BlinkApp extends Component
//{
//    render ()
//    {
//        return (
//                <View>
//                    <Blink text='I love to blink' />
//                    <Blink text='Yes blinking is so great' />
//                    <Blink text='Why did they ever take this out of HTML' />
//                    <Blink text='Look at me look at me look at me' />
//
//                </View>
//        );
//    }
//}
//
//AppRegistry.registerComponent('XiaoTuanTest' , () => BlinkApp);




//样式
import React , { Component } from 'react' ;
import { AppRegistry , StyleSheet , View , Text } from 'react-native' ;

class LotsOfStyles extends Component
{
    render()
    {
        return (
                <View>
                <Text style = { styles.red } > just red </Text>
                <Text style = { styles.bigblue } > just bigblue </Text>
                <Text style = { [styles.bigblue ,styles.red] } > bigblue, then red </Text>
                <Text style={ [styles.red, styles.bigblue] } > red, then bigblue </Text>

                </View>
        );
    }
}

const styles = StyleSheet.create(
{
     bigblue :{
         color : 'blue',
         fontSize: 30 ,
         fontWeight : 'bold',
     },
     
     red:{
         color:'red' ,
     },

}
);

AppRegistry.registerComponent('XiaoTuanTest' , () => LotsOfStyles);


//默认
//import React, { Component } from 'react';
//import {
//  AppRegistry,
//  StyleSheet,
//  Text,
//  View
//} from 'react-native';
//
//export default class XiaoTuanTest extends Component {
//  render() {
//    return (
//      <View style={styles.container}>
//        <Text style={styles.welcome}>
//          Welcome to React Native!
//        </Text>
//        <Text style={styles.instructions}>
//          To get started, edit index.ios.js
//        </Text>
//        <Text style={styles.instructions}>
//          Press Cmd+R to reload,{'\n'}
//          Cmd+D or shake for dev menu
//        </Text>
//      </View>
//    );
//  }
//}
//
//const styles = StyleSheet.create({
//  container: {
//    flex: 1,
//    justifyContent: 'center',
//    alignItems: 'center',
//    backgroundColor: '#F5FCFF',
//  },
//  welcome: {
//    fontSize: 20,
//    textAlign: 'center',
//    margin: 10,
//  },
//  instructions: {
//    textAlign: 'center',
//    color: '#333333',
//    marginBottom: 5,
//  },
//});
//
//AppRegistry.registerComponent('XiaoTuanTest', () => XiaoTuanTest);

