/************************************************************
 *  * Hyphenate CONFIDENTIAL
 * __________________
 * Copyright (C) 2016 Hyphenate Inc. All rights reserved.
 *
 * NOTICE: All information contained herein is, and remains
 * the property of Hyphenate Inc.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Hyphenate Inc.
 */

#ifndef EaseLocalDefine_h
#define EaseLocalDefine_h
#import "EaseMessageViewController.h"

#define iPhoneX_BOTTOM_HEIGHT  ([UIScreen mainScreen].bounds.size.height==812?34:0)


#define NSEaseLocalizedString(key, comment) [[NSBundle bundleForClass:[EaseMessageViewController class]] localizedStringForKey:(key) value:@"" table:nil]
//#define NSEaseLocalizedString(key, comment) [[NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:@"EaseUIResource" withExtension:@"bundle"]] localizedStringForKey:(key) value:@"" table:nil]

// Views
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

#define DocumentPath  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

// 取色值相关的方法
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RandomColor RGBA(arc4random_uniform(255), arc4random_uniform(255), arc4random_uniform(255), 1)

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

#define WeakSelf  __weak __typeof(self)weakSelf = self;

//状态栏高度
#define KStatusBarHeight  [[UIApplication sharedApplication] statusBarFrame].size.height
#define KNavContentHeight     44.0
//整个导航栏高度
#define KNavBarHeight        (KStatusBarHeight + KNavContentHeight)
//底部tabbar高度
#define KTabBarHeight     ([[UIApplication sharedApplication] statusBarFrame].size.height > 20 ? 83 : 49)

#endif /* EaseLocalDefine_h */





