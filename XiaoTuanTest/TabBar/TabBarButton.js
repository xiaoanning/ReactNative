
import React , { Component , PropTypes } from 'react' ;
import { Button , View , Image , Text , TouchableHighlight , StyleSheet , Alert } from 'react-native' ;

export default class TabBarButton extends Component
{
    constructor(props)
    {
        super(props) ;
        this.state = { pressed : false , hidden : false , test : false} ;
    }
    
    static propTypes =
    {
        superStyle: View.propTypes.style ,
        titleT: PropTypes.string.isRequired ,
        textStyle: View.propTypes.style ,
        onPresss : PropTypes.func.isRequired ,

    }
    

    render ()
    {
        this.state.test ? console.log('true') : console.log('false');
        this.state.hidden ? console.log(' hidden true') : console.log('hidden false');
        this.state.pressed ? console.log(' pressed true') : console.log('pressed false');

        return (
                <Button style = { this.props.superStyle } title = { this.props.titleT } onPress = { this.props.onPresss } />
                )
    }
}
