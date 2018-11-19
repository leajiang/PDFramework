//
//  EaseMessageRemindCell.h
//  PDChat
//
//  Created by PD_Zzzzzzz on 2018/10/17.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EaseMessageRemindCell : UITableViewCell


@property (strong, nonatomic) NSString *title;

/*
 *  提示显示字体
 */
@property (nonatomic) UIFont *remindLabelFont UI_APPEARANCE_SELECTOR; //default [UIFont systemFontOfSize:12]

/*
 *  提示显示颜色
 */
@property (nonatomic) UIColor *remindLabelColor UI_APPEARANCE_SELECTOR; //default [UIColor grayColor]

+ (NSString *)cellIdentifier;

@end
