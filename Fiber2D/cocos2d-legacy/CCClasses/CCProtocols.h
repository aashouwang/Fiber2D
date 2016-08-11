/*
 * Cocos2D-SpriteBuilder: http://cocos2d.spritebuilder.com
 *
 * Copyright (c) 2008-2010 Ricardo Quesada
 * Copyright (c) 2011 Zynga Inc.
 * Copyright (c) 2013-2014 Cocos2D Authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#import "ccTypes.h"


@class CCTexture;
@class CCBlendMode;
@class CCShader;
@class CCRenderState;
@class CCEffect;

#pragma mark - CCShaderProtocol

/// Properties for controlling the shader of a Node when it renders.
/// These properties are already implemented by Node, but not normally exposed.
@protocol CCShaderProtocol <NSObject>

@optional

/// The shader this node will be drawn using.
@property(nonatomic, strong) CCShader *shader;
/// The dictionary of shader uniform values that will be passed to the shader.
@property(nonatomic, readonly) NSMutableDictionary *shaderUniforms;
/// True if the node is not using custom uniforms.
@property(nonatomic, readonly) BOOL usesCustomShaderUniforms;


/// The rendering state this node will use when rendering.
@property(nonatomic, readonly, strong) CCRenderState *renderState;

@end

#pragma mark - CCBlendProtocol
/**
 You can specify the blending function.
 */
@protocol CCBlendProtocol <NSObject>

@optional

/// The blending mode that will be used to render this node.
@property(nonatomic, readwrite, strong) CCBlendMode *blendMode;

/// The rendering state this node will use when rendering.
@property(nonatomic, readonly, strong) CCRenderState *renderState;

@end


#pragma mark - CCTextureProtocol

/** Node objects that uses a Texture2D to render the images.
 The texture can have a blending function.
 If the texture has alpha premultiplied the default blending function is:
    src=GL_ONE dst= GL_ONE_MINUS_SRC_ALPHA
 else
	src=GL_SRC_ALPHA dst= GL_ONE_MINUS_SRC_ALPHA
 But you can change the blending function at any time.
 */
@protocol CCTextureProtocol <CCBlendProtocol>

@optional

/// The main texture that will be passed to this node's shader.
@property(nonatomic, strong) CCTexture *texture;

/// The secondary texture that will be passed to this node's shader.
@property(nonatomic, strong) CCTexture *secondaryTexture;

/// The rendering state this node will use when rendering.
@property(nonatomic, readonly, strong) CCRenderState *renderState;

@end


#pragma mark - CCLabelProtocol
/** Common interface for Labels */
@protocol CCLabelProtocol <NSObject>
/** sets a new label using an NSString.
 The string will be copied.
 */
-(void) setString:(NSString*)label;
/** returns the string that is rendered */
-(NSString*) string;
@optional
/** sets a new label using a CString.
 */
-(void) setCString:(char*)label;
@end