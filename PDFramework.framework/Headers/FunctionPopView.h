//
//  FunctionPopView.h
//  PDChat
//
//  Created by PD_Zzzzzzz on 2018/10/16.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FunctionPopView : UIView


+ (void)showPopViewWithTitles:(NSArray *)titles flag:(NSArray *)indexs IndexBlock:(void(^)(NSInteger index,UIButton *button))block;


@end
