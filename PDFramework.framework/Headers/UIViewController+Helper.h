//
//  UIViewController+Helper.h
//  GH
//
//  Created by apple on 15/11/23.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (Helper)
-(void)popViewController:(NSInteger)index;
-(void)popViewToController:(UIViewController *)controller;
+ (UIViewController *)getCurrentVC;
@end
