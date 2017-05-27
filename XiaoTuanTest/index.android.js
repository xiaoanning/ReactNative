/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

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
//          To get started, edit index.android.js
//        </Text>
//        <Text style={styles.instructions}>
//          Double tap R on your keyboard to reload,{'\n'}
//          Shake or press menu button for dev menu
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


////图片
//import React , { Component } from 'react' ;
//import { AppRegistry , Image } from 'react-native' ;
//
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


//import React , { Component }  from 'react' ;
//import { AppRegistry , View , Text } from 'react-native' ;
//
//class XiaoTuanTest extends Component
//{
//    getMoviesFromApiAsync() {
//        return fetch('http://facebook.github.io/react-native/movies.json')
//        .then((response) => response.json())
//        .then((responseJson) => {
//              return responseJson.movies;
//              })
//        .catch((error) => {
//               console.error(error);
//               });
//    }
//
//    render()
//    {
//        return (
//                <Text style = {{ top:20 }}>02020== </Text>
//                ) ;
//    }
//}
//
//AppRegistry.registerComponent('XiaoTuanTest' , () => XiaoTuanTest);


import React , { Component } from 'react' ;
import { AppRegistry , Navigator } from 'react-native' ;
import MyScene from './MyScene' ;
class App extends Component
{
    render()
    {
        return (
            <Navigator
                initialRoute = {{ title :  'My Initial Scene' , index : 0}}
                renderScene = { (route , navigator) =>
                <MyScene title = { route.title }
                onForward =
                { () =>
                    { const nextIndex = route.index + 1 ;
                        navigator.push({
                           title : 'Scene' + nextIndex,
                           index : nextIndex
                       });
                    }
                }
                
                onBack =
                {
                    () =>
                    {
                        if(route.index > 0)
                        {
                            navigator.pop();
                        }
                    }
                }
                
                onLongPressTip =
                {
                    () =>
                    {
                        console.log('长按');
                    }
                }
                
                />
                }
            />
                
                );
    }
}

AppRegistry.registerComponent( 'XiaoTuanTest' , () => App);



//import React , { Component } from 'react' ;
//import { AppRegistry  } from 'react-native' ;
//import ImageTest from './ImageTest' ;
//class App extends Component
//{
//    render()
//    {
//        console.log('zhe shi shuchu');
//        return (
//                    <ImageTest />
//                );
//    }
//}
//
//AppRegistry.registerComponent( 'XiaoTuanTest' , () => App);

