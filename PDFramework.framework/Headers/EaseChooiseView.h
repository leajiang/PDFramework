//
//  EaseChooiseView.h
//  PDChat
//
//  Created by PeiDou on 2018/10/16.
//  Copyright © 2018年 PeiDou. All rights reserved.
//

#import "BaseAlphaView.h"

typedef void(^ChooiseViewBlock)(NSString * string);

@interface EaseChooiseView : BaseAlphaView
@property(copy,nonatomic)ChooiseViewBlock block;
- (instancetype)initWithFrame:(CGRect)frame array:(NSArray *)tmpTitleArray block:(ChooiseViewBlock)block;
-(void)defaultButtonSelect:(NSNumber *)number;
@end
