网络

很多移动应用都需要从远程地址中获取数据或资源。你可能需要给某个REST API发起POST请求以提交用户数据，又或者可能仅仅需要从某个服务器上获取一些静态内容——以下就是你会用到的东西。新手可以对照这个简短的视频教程加深理解。

使用Fetch
React Native提供了和web标准一致的Fetch API，用于满足开发者访问网络的需求。如果你之前使用过XMLHttpRequest(即俗称的ajax)或是其他的网络API，那么Fetch用起来将会相当容易上手。这篇文档只会列出Fetch的基本用法，并不会讲述太多细节，你可以使用你喜欢的搜索引擎去搜索fetch api关键字以了解更多信息。

发起网络请求

要从任意地址获取内容的话，只需简单地将网址作为参数传递给fetch方法即可（fetch这个词本身也就是获取的意思）：

fetch('https://mywebsite.com/mydata.json')
Fetch还有可选的第二个参数，可以用来定制HTTP请求一些参数。你可以指定header参数，或是指定使用POST方法，又或是提交数据等等：

fetch('https://mywebsite.com/endpoint/', {
method: 'POST',
headers: {
    'Accept': 'application/json',
    'Content-Type': 'application/json',
},
body: JSON.stringify({
firstParam: 'yourValue',
secondParam: 'yourOtherValue',
})
})
译注：如果你的服务器无法识别上面POST的数据格式，那么可以尝试传统的form格式，示例如下：

fetch('https://mywebsite.com/endpoint/', {
method: 'POST',
headers: {
    'Content-Type': 'application/x-www-form-urlencoded',
},
body: 'key1=value1&key2=value2'
})
可以参考Fetch请求文档来查看所有可用的参数。

处理服务器的响应数据

上面的例子演示了如何发起请求。很多情况下，你还需要处理服务器回复的数据。

网络请求天然是一种异步操作（译注：同样的还有asyncstorage，请不要再问怎样把异步变成同步！无论在语法层面怎么折腾，它们的异步本质是无法变更的。异步的意思是你应该趁这个时间去做点别的事情，比如显示loading，而不是让界面卡住傻等）。Fetch 方法会返回一个Promise，这种模式可以简化异步风格的代码（译注：同样的，如果你不了解promise，建议使用搜索引擎补课）：

getMoviesFromApiAsync() {
    return fetch('http://facebook.github.io/react-native/movies.json')
    .then((response) => response.json())
    .then((responseJson) => {
        return responseJson.movies;
    })
    .catch((error) => {
        console.error(error);
    });
}
你也可以在React Native应用中使用ES7标准中的async/await 语法：

// 注意这个方法前面有async关键字
async getMoviesFromApi() {
    try {
        // 注意这里的await语句，其所在的函数必须有async关键字声明
        let response = await fetch('http://facebook.github.io/react-native/movies.json');
        let responseJson = await response.json();
        return responseJson.movies;
    } catch(error) {
        console.error(error);
    }
}
别忘了catch住fetch可能抛出的异常，否则出错时你可能看不到任何提示。

默认情况下，iOS会阻止所有非HTTPS的请求。如果你请求的接口是http协议，那么首先需要添加一个App Transport Securty的例外，详细可参考这篇帖子。
使用其他的网络库
React Native中已经内置了XMLHttpRequest API(也就是俗称的ajax)。一些基于XMLHttpRequest封装的第三方库也可以使用，例如frisbee或是axios等。但注意不能使用jQuery，因为jQuery中还使用了很多浏览器中才有而RN中没有的东西（所以也不是所有web中的ajax库都可以直接使用）。

var request = new XMLHttpRequest();
request.onreadystatechange = (e) => {
    if (request.readyState !== 4) {
        return;
    }
    
    if (request.status === 200) {
        console.log('success', request.responseText);
    } else {
        console.warn('error');
    }
};

request.open('GET', 'https://mywebsite.com/endpoint/');
request.send();
需要注意的是，安全机制与网页环境有所不同：在应用中你可以访问任何网站，没有跨域的限制。
WebSocket支持
React Native还支持WebSocket，这种协议可以在单个TCP连接上提供全双工的通信信道。

var ws = new WebSocket('ws://host.com/path');

ws.onopen = () => {
    // 打开一个连接
    
    ws.send('something'); // 发送一个消息
};

ws.onmessage = (e) => {
    // 接收到了一个消息
    console.log(e.data);
};

ws.onerror = (e) => {
    // 发生了一个错误
    console.log(e.message);
};

ws.onclose = (e) => {
    // 连接被关闭了
    console.log(e.code, e.reason);
};
现在你的应用已经可以从各种渠道获取数据了，那么接下来面临的问题多半就是如何在不同的页面间组织和串联内容了。要管理页面的跳转，你需要学习使用导航器。
