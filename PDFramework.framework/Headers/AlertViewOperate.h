//
//  AlertViewOperate.h
//  GH
//
//  Created by apple on 15/9/16.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^AlertDoneBlock)(BOOL done);
typedef void (^AlertInputDoneBlock)(NSString *text,BOOL done);

@interface AlertViewOperate : NSObject<UIAlertViewDelegate>
+ (AlertViewOperate *)shareAlert;
- (void)alertWithTitle:(NSString *)title
                      message:(NSString *)message
                       cancel:(NSString *)cancel
                        other:(NSString *)other
                    doneBlock:(AlertDoneBlock)doneBlock;

- (void)alertWithInput:(NSString *)inputText
                      message:(NSString *)message
                       cancel:(NSString *)cancel
                        other:(NSString *)other
                    doneBlock:(AlertInputDoneBlock)block;

@property(copy,nonatomic)AlertDoneBlock doneBlock;
@property(copy,nonatomic)AlertInputDoneBlock inputDoneBlock;
@end
