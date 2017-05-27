
import React , { Component } from 'react' ;
import { View , Text , Image } from 'react-native' ;

export default class ImageTest extends Component
{
    render ()
    {
        return (
            <Image style = {{ top:40}} source = { require( './img/ser6.png')}>
                <Text> Current Image first test </Text>
            </Image>
                )
    }
}
