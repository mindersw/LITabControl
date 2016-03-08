//
//  LITabCell.h
//  LITabControl
//
//  Created by Mark Onyschuk on 11/17/2013.
//  Copyright (c) 2013 Mark Onyschuk. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef enum {
    LIBorderMaskTop     = (1<<0),
    LIBorderMaskLeft    = (1<<1),
    LIBorderMaskRight   = (1<<2),
    LIBorderMaskBottom  = (1<<3)
} LIBorderMask;

@protocol LITabViewDelegate;

@interface LITabCell : NSButtonCell

@property (nonatomic, assign) id delegate;
@property(nonatomic, copy) NSUUID *tabUUID;

@property(nonatomic) BOOL showsMenu;
@property(readonly, nonatomic) BOOL isShowingMenu;

@property(nonatomic) CGFloat borderWidth;
@property(nonatomic) LIBorderMask borderMask;
@property(nonatomic, copy) NSColor *borderColor;
@property(nonatomic, copy) NSColor *backgroundColor;

@property(nonatomic, copy) NSColor *titleColor;
@property(nonatomic, copy) NSColor *titleHighlightColor;

@property(nonatomic) CGFloat minWidth, maxWidth;

// NOTE:
// Returns an adjusted field editor frame
// used when editing the cell's title. Override
// if cell contents appear to shift while editing
//  Copyright (c) 2016 Michael LaMorte. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

- (NSRect)editingRectForBounds:(NSRect)rect;

@end

@protocol LITabViewDelegate <NSObject>
- (void)closeTabHandler:(NSUUID *)tabUUID;
@end

@interface LITabButton : NSButton
+ (Class)cellClass;

@property(nonatomic) BOOL showsMenu;
@property(readonly, nonatomic) BOOL isShowingMenu;

@property(nonatomic) LIBorderMask borderMask;
@property(nonatomic, copy) NSColor *borderColor;
@property(nonatomic, copy) NSColor *backgroundColor;

@property(nonatomic, copy) NSColor *titleColor;
@property(nonatomic, copy) NSColor *titleHighlightColor;

@property(nonatomic) CGFloat minWidth, maxWidth;

@end

extern BOOL LIRectArrayWithBorderMask(NSRect sourceRect, CGFloat borderWidth, LIBorderMask borderMask, NSRect **rectArray, NSInteger *rectCount);
