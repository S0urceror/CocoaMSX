/*****************************************************************************
 **
 ** CocoaMSX: MSX Emulator for Mac OS X
 ** http://www.cocoamsx.com
 ** Copyright (C) 2012-2016 Akop Karapetyan
 **
 ** This program is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 **
 ******************************************************************************
 */
#import <Cocoa/Cocoa.h>

#import "CMGamepadManager.h"
#import "CMKeyboardManager.h"

@class CMGamepadConfiguration;

@protocol CMGamepadConfigurationDelegate

@required
- (void) gamepadConfigurationDidComplete:(CMGamepadConfiguration *) configuration;

@end

@interface CMConfigureJoystickController : NSWindowController<NSWindowDelegate, NSTableViewDataSource, CMGamepadEventDelegate, CMKeyboardEventDelegate>
{
    IBOutlet NSButton *saveButton;
	IBOutlet NSTableView *tableView;
	IBOutlet NSTextField *infoLabel;
}

@property (nonatomic, weak) id delegate;

- (void) configureGamepadId:(NSInteger) gamepadId
	  existingConfiguration:(CMGamepadConfiguration *) existing;

- (IBAction) resetToDefault:(id) sender;
- (IBAction) cancelChanges:(id) sender;
- (IBAction) saveChanges:(id) sender;

@end
