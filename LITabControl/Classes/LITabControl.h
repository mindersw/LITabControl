//
//  LITabControl.h
//  LITabControl
//
//  Created by Mark Onyschuk on 11/12/2013.
//  Copyright (c) 2013 Mark Onyschuk. All rights reserved.
//
//  Copyright (c) 2016 Michael LaMorte. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import "LITabCell.h"

@class LITabControl;

@protocol LITabDataSource <NSObject>

- (NSUInteger)tabControlNumberOfTabs:(LITabControl *)tabControl;

- (id)tabControl:(LITabControl *)tabControl itemAtIndex:(NSUInteger)index;

- (NSMenu *)tabControl:(LITabControl *)tabControl menuForItem:(id)item;

- (NSString *)tabControl:(LITabControl *)tabControl titleForItem:(id)item;
- (NSUUID *)tabControl:(LITabControl *)tabControl UUIDforItem:(id)item;
- (void)tabControl:(LITabControl *)tabControl setTitle:(NSString *)title forItem:(id)item;

- (BOOL)tabControl:(LITabControl *)tabControl canReorderItem:(id)item;
- (void)tabControlDidReorderItems:(LITabControl *)tabControl orderedItems:(NSArray *)itemArray;

- (void)removeTabWithUUID:(NSUUID *)uuid;
- (void)makeNewTabWithName:(NSString *)tabName index:(int)index;

@optional
- (void)tabControlDidChangeSelection:(NSNotification *)notification;

- (BOOL)tabControl:(LITabControl *)tabControl canEditItem:(id)item;
- (BOOL)tabControl:(LITabControl *)tabControl canSelectItem:(id)item;

- (void)tabControl:(LITabControl *)tabControl willDisplayButton:(LITabButton *)button forItem:(id)item;

@end

@protocol LITabDelegate <NSControlTextEditingDelegate>
@end

extern NSString *LITabControlSelectionDidChangeNotification;

@interface LITabControl : NSControl

#pragma mark -
#pragma mark Display Properties

@property(nonatomic) CGFloat borderWidth;
@property(nonatomic, copy) NSColor *borderColor;
@property(nonatomic, copy) NSColor *backgroundColor;

@property(nonatomic, copy) NSColor *titleColor;
@property(nonatomic, copy) NSColor *titleHighlightColor;

#pragma mark -
#pragma mark Delegate & Data Source

@property(nonatomic, weak) id <LITabDelegate> delegate;
@property(nonatomic, weak) id <LITabDataSource> dataSource;

- (void)reloadData;

#pragma mark -
#pragma mark Selection

@property(nonatomic, weak) id selectedItem;

#pragma mark -
#pragma mark Target/Action

@property(nonatomic) SEL addAction;
@property(nonatomic, weak) id addTarget;

#pragma mark -
#pragma mark Editing

- (void)editItem:(id)item;

#pragma mark -
#pragma mark Tab Buttons

+ (Class)tabButtonClass;

- (NSArray *)tabButtons;
- (NSButton *)tabButtonWithItem:(id)item;

#pragma mark -
#pragma mark Reordering

@property(nonatomic) BOOL notifiesOnPartialReorder;

@end
