//
//  SRRecorderCell.h
//  ShortcutRecorder
//
//  Copyright 2006-2007 Contributors. All rights reserved.
//
//  License: BSD
//
//  Contributors:
//      David Dauer
//      Jesper
//      Jamie Kirkpatrick

#import <Cocoa/Cocoa.h>

#import "SRCommon.h"

#define SRMinWidth 50
#define SRMinHeight 17

#define SRTransitionFPS 30.0f
#define SRTransitionDuration 0.35f
//#define SRTransitionDuration 2.35
#define SRTransitionFrames (SRTransitionFPS*SRTransitionDuration)
#define SRAnimationAxisIsY YES
#define ShortcutRecorderNewStyleDrawing

#define SRAnimationOffsetRect(X,Y)	(SRAnimationAxisIsY ? NSOffsetRect(X,0.0f,-NSHeight(Y)) : NSOffsetRect(X,NSWidth(Y),0.0f))

@class SRRecorderControl, SRValidator;

@interface SRRecorderCell : NSActionCell <NSCoding>
{	
	NSGradient          *recordingGradient;
	
	BOOL                isRecording;
	BOOL                mouseInsideRemoveTrackingArea;
	BOOL                mouseDown;
    BOOL                isRowSelected; // for tableCellMode
	
	BOOL				isAnimating;
	CGFloat				transitionProgress;
	BOOL				isAnimatingNow;
	BOOL				isAnimatingTowardsRecording;
	BOOL				comboJustChanged;
	
	NSTrackingRectTag   removeTrackingRectTag;
	
	KeyCombo            keyCombo;
	BOOL				hasKeyChars;
	NSString		    *keyChars;
	NSString		    *keyCharsIgnoringModifiers;
	
	NSUInteger        allowedFlags;
	NSUInteger        requiredFlags;
	NSUInteger        recordingFlags;
	
    BOOL                useSingleKeyMode;
    BOOL                tableCellMode;
	BOOL				allowsKeyOnly;
	BOOL				escapeKeysRecord;
	
	NSSet               *cancelCharacterSet;
	
    SRValidator         *validator;
    
	IBOutlet id         delegate;
	BOOL				globalHotKeys;
	void				*hotKeyModeToken;
}

- (void)resetTrackingRects;

#pragma mark *** Aesthetics ***

- (BOOL)animates;
- (void)setAnimates:(BOOL)an;

#pragma mark *** Delegate ***

- (id)delegate;
- (void)setDelegate:(id)aDelegate;

#pragma mark *** Responder Control ***

- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;

#pragma mark *** Key Combination Control ***

- (BOOL)performKeyEquivalent:(NSEvent *)theEvent;
- (void)flagsChanged:(NSEvent *)theEvent;

- (NSUInteger)allowedFlags;
- (void)setAllowedFlags:(NSUInteger)flags;

- (NSUInteger)requiredFlags;
- (void)setRequiredFlags:(NSUInteger)flags;

- (BOOL)useSingleKeyMode;
- (void)setUseSingleKeyMode:(BOOL)singleKey;

- (BOOL)tableCellMode;
- (void)setTableCellMode:(BOOL)mode;

- (BOOL)allowsKeyOnly;
- (void)setAllowsKeyOnly:(BOOL)nAllowsKeyOnly;
- (void)setAllowsKeyOnly:(BOOL)nAllowsKeyOnly escapeKeysRecord:(BOOL)nEscapeKeysRecord;
- (BOOL)escapeKeysRecord;
- (void)setEscapeKeysRecord:(BOOL)nEscapeKeysRecord;

- (BOOL)canCaptureGlobalHotKeys;
- (void)setCanCaptureGlobalHotKeys:(BOOL)inState;

- (KeyCombo)keyCombo;
- (void)setKeyCombo:(KeyCombo)aKeyCombo;

// Returns the displayed key combination if set
- (NSString *)keyComboString;

- (NSString *)keyChars;
- (NSString *)keyCharsIgnoringModifiers;

@end

// Delegate Methods
@interface NSObject (SRRecorderCellDelegate)
- (BOOL)shortcutRecorderCell:(SRRecorderCell *)aRecorderCell isKeyCode:(NSInteger)keyCode andFlagsTaken:(NSUInteger)flags reason:(NSString **)aReason;
- (void)shortcutRecorderCell:(SRRecorderCell *)aRecorderCell keyComboDidChange:(KeyCombo)newCombo;
@end