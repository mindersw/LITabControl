//
//  LIAppDelegate.m
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

#import "LIAppDelegate.h"

@implementation LIAppDelegate {
    NSArray *_tabs;
    NSMenu  *_menu;
    
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [self.window setBackgroundColor:[NSColor whiteColor]];
    
    _menu = [[NSMenu alloc] init];
    _tabs = @[];

    [self.tabControl setDataSource:self];

    [_menu addItem:[NSMenuItem separatorItem]];
    [[_menu addItemWithTitle:NSLocalizedString(@"Menu Action", nil) action:@selector(menuAction:) keyEquivalent:@""] setTarget:self];

    NSArray *tabNames = @[@"Sheet 1", @"Sheet 2", @"Sheet 3", @"Sheet 4", @"Sheet 5"];
    for (int i = 0; i < [tabNames count]; i++) {
        [self makeNewTabWithName:[tabNames objectAtIndex:i] index:i];
    }
    
}

- (IBAction)menuAction:(id)sender {
    NSLog(@"%s", __PRETTY_FUNCTION__);
}

#pragma mark -
#pragma mark Tab Controls
- (void)makeNewTabWithName:(NSString *)tabName index:(int)index {
    
    int idx = index;
    if (idx == -1) idx = (int)[_tabs count];
    
    NSDictionary *tabData = [NSDictionary dictionaryWithObjectsAndKeys:tabName, @"tabName", [NSUUID UUID], @"tabUUID", [NSNumber numberWithInt:idx], @"tabIndex", nil];
    
    NSMutableArray *tabs = [[NSMutableArray alloc] initWithArray:_tabs];
    [tabs insertObject:tabData atIndex:idx];
    _tabs = tabs;
    
    [self.tabControl reloadData];
    [self.tabControl setSelectedItem:tabData];
}

#pragma mark -
#pragma mark LITabControlDataSource

- (NSUInteger)tabControlNumberOfTabs:(LITabControl *)tabControl {
    return _tabs.count;
}

- (id)tabControl:(LITabControl *)tabControl itemAtIndex:(NSUInteger)index {
    return _tabs[index];
}

- (NSMenu *)tabControl:(LITabControl *)tabControl menuForItem:(id)item {
    return _menu;
}

- (NSString *)tabControl:(LITabControl *)tabControl titleForItem:(id)item {
    return [item valueForKey:@"tabName"];
}

- (NSUUID *)tabControl:(LITabControl *)tabControl UUIDforItem:(id)item {
    return [item objectForKey:@"tabUUID"];
}

- (void)tabControl:(LITabControl *)tabControl setTitle:(NSString *)title forItem:(id)item {
}

- (BOOL)tabControl:(LITabControl *)tabControl canReorderItem:(id)item {
    return YES;
}

- (void)tabControlDidReorderItems:(LITabControl *)tabControl orderedItems:(NSArray *)itemArray {
    _tabs = itemArray;
}

- (void)tabControlDidChangeSelection:(NSNotification *)notification {
    NSLog(@"%s (selected item = %@)", __PRETTY_FUNCTION__, self.tabControl.selectedItem);
}

- (void)removeTabWithUUID:(NSUUID *)uuid {
    NSMutableArray *tabs = [[NSMutableArray alloc] initWithArray:_tabs];
    NSDictionary *tab;
    for (tab in _tabs) {
        if ([[tab objectForKey:@"tabUUID"] isEqualTo:uuid]) {
            [tabs removeObject:tab];
        }
        
        _tabs = tabs;
        [self.tabControl reloadData];
    }
}

@end
