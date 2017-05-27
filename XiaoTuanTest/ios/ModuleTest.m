//
//  ModuleTest.m
//  XiaoTuanTest
//
//  Created by 安宁 on 2017/4/6.
//  Copyright © 2017年 Facebook. All rights reserved.
//

#import "ModuleTest.h"
#import <React/RCTConvert.h>

@implementation ModuleTest

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(processString:(NSString *)input callback:(RCTResponseSenderBlock)callback)
{
  RCTLogInfo(@"%d %s %s %@ %@",__LINE__,__func__,__FILE__,input,callback);
  callback(@[@"zheshi callback"]);
  
}

@end
