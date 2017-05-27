布局样式属性

alignItems enum('flex-start', 'flex-end', 'center', 'stretch')

alignItems决定了子元素在次轴方向的排列方式（此样式设置在父元素上）。例如若子元素本来是沿着竖直方向排列的（即主轴竖直，次轴水平），则alignItems决定了它们在水平方向的排列方式。此样式和CSS中的align-items表现一致，默认值为stretch。访问https://developer.mozilla.org/en-US/docs/Web/CSS/align-items来进一步了解。

alignSelf enum('auto', 'flex-start', 'flex-end', 'center', 'stretch')

alignSelf决定了元素在父元素的次轴方向的排列方式（此样式设置在子元素上），其值会覆盖父元素的alignItems的值。其表现和CSS上的align-self一致（默认值为auto）。访问https://developer.mozilla.org/en-US/docs/Web/CSS/align-self来进一步了解。

borderBottomWidth number

borderBottomWidth和CSS上的border-bottom-width表现一致。访问https://developer.mozilla.org/en-US/docs/Web/CSS/border-bottom-width来进一步了解。

borderLeftWidth number

borderLeftWidth和CSS上的border-left-width表现一致。访问https://developer.mozilla.org/en-US/docs/Web/CSS/border-left-width来进一步了解。

borderRightWidth number

borderRightWidth 和CSS上的border-right-width表现一致。访问https://developer.mozilla.org/en-US/docs/Web/CSS/border-right-width来进一步了解。

borderTopWidth number

borderTopWidth和CSS上的border-top-width表现一致。访问https://developer.mozilla.org/en-US/docs/Web/CSS/border-top-width来进一步了解。

borderWidth number

borderWidth和CSS上的border-width表现一致。访问https://developer.mozilla.org/en-US/docs/Web/CSS/border-width来进一步了解。

bottom number

bottom值是指将本组件定位到距离底部多少个逻辑像素（底部的定义取决于position属性）。

它的表现和CSS上的bottom类似，但注意在React Native上只能使用逻辑像素值（数字单位），而不能使用百分比、em或是任何其他单位。

访问https://developer.mozilla.org/en-US/docs/Web/CSS/bottom来进一步了解bottom是如何影响布局的。

flex number

在React Native中flex的表现和CSS有些区别。 flex在RN中只能为整数值，其具体表现请参考yoga引擎库的文档，其网址是https://github.com/facebook/yoga

当flex取正整数值时， is a positive number, it makes the component flexible and it will be sized proportional to its flex value. So a component with flex set to 2 will take twice the space as a component with flex set to 1.

When flex is 0, the component is sized according to width and height and it is inflexible.

When flex is -1, the component is normally sized according width and height. However, if there's not enough space, the component will shrink to its minWidth and minHeight.

flexGrow, flexShrink, and flexBasis work the same as in CSS.

flexBasis number

flexDirection enum('row', 'row-reverse', 'column', 'column-reverse')

flexDirection controls which directions children of a container go. row goes left to right, column goes top to bottom, and you may be able to guess what the other two do. It works like flex-direction in CSS, except the default is column.访问https://developer.mozilla.org/en-US/docs/Web/CSS/flex-direction来进一步了解。

flexGrow number

flexShrink number

flexWrap enum('wrap', 'nowrap')

flexWrap controls whether children can wrap around after they hit the end of a flex container. It works like flex-wrap in CSS (default: nowrap).访问https://developer.mozilla.org/en-US/docs/Web/CSS/flex-wrap来进一步了解。

height number

height用于设置组件的高度。

It works similarly to height in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.访问https://developer.mozilla.org/en-US/docs/Web/CSS/height来进一步了解。

justifyContent enum('flex-start', 'flex-end', 'center', 'space-between', 'space-around')

justifyContent aligns children in the main direction. For example, if children are flowing vertically, justifyContent controls how they align vertically. It works like justify-content in CSS (default: flex-start).访问https://developer.mozilla.org/en-US/docs/Web/CSS/justify-content来进一步了解。

left number

left值是指将本组件定位到距离左边多少个逻辑像素（左边的定义取决于position属性）。

它的表现和CSS上的left类似，但注意在React Native上只能使用逻辑像素值（数字单位），而不能使用百分比、em或是任何其他单位。

访问https://developer.mozilla.org/en-US/docs/Web/CSS/left来进一步了解left是如何影响布局的。

margin number

Setting margin has the same effect as setting each of marginTop, marginLeft, marginBottom, and marginRight.访问https://developer.mozilla.org/en-US/docs/Web/CSS/margin来进一步了解。

marginBottom number

marginBottom works like margin-bottom in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/margin-bottom来进一步了解。

marginHorizontal number

Setting marginHorizontal has the same effect as setting both marginLeft and marginRight.

marginLeft number

marginLeft works like margin-left in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/margin-left来进一步了解。

marginRight number

marginRight works like margin-right in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/margin-right来进一步了解。

marginTop number

marginTop works like margin-top in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/margin-top来进一步了解。

marginVertical number

Setting marginVertical has the same effect as setting both marginTop and marginBottom.

maxHeight number

maxHeight is the maximum height for this component, in logical pixels.

It works similarly to max-height in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.

访问https://developer.mozilla.org/en-US/docs/Web/CSS/max-height来进一步了解。

maxWidth number

maxWidth is the maximum width for this component, in logical pixels.

It works similarly to max-width in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.

访问https://developer.mozilla.org/en-US/docs/Web/CSS/max-width来进一步了解。

minHeight number

minHeight is the minimum height for this component, in logical pixels.

It works similarly to min-height in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.

访问https://developer.mozilla.org/en-US/docs/Web/CSS/min-height来进一步了解。

minWidth number

minWidth is the minimum width for this component, in logical pixels.

It works similarly to min-width in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.

访问https://developer.mozilla.org/en-US/docs/Web/CSS/min-width来进一步了解。

overflow enum('visible', 'hidden', 'scroll')

overflow controls how a children are measured and displayed. overflow: hidden causes views to be clipped while overflow: scroll causes views to be measured independently of their parents main axis.It works likeoverflow` in CSS (default: visible).访问https://developer.mozilla.org/en/docs/Web/CSS/overflow来进一步了解。

padding number

Setting padding has the same effect as setting each of paddingTop, paddingBottom, paddingLeft, and paddingRight.访问https://developer.mozilla.org/en-US/docs/Web/CSS/padding来进一步了解。

paddingBottom number

paddingBottom works like padding-bottom in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/padding-bottom来进一步了解。

paddingHorizontal number

Setting paddingHorizontal is like setting both of paddingLeft and paddingRight.

paddingLeft number

paddingLeft works like padding-left in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/padding-left来进一步了解。

paddingRight number

paddingRight works like padding-right in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/padding-right来进一步了解。

paddingTop number

paddingTop works like padding-top in CSS.访问https://developer.mozilla.org/en-US/docs/Web/CSS/padding-top来进一步了解。

paddingVertical number

Setting paddingVertical is like setting both of paddingTop and paddingBottom.

position enum('absolute', 'relative')

position in React Native is similar to regular CSS, but everything is set to relative by default, so absolute positioning is always just relative to the parent.

If you want to position a child using specific numbers of logical pixels relative to its parent, set the child to have absolute position.

If you want to position a child relative to something that is not its parent, just don't use styles for that. Use the component tree.

访问https://facebook.github.io/yoga/docs/absolute-position/来进一步了解position在React Native和CSS中的差异。

right number

right值是指将本组件定位到距离右边多少个逻辑像素（右边的定义取决于position属性）。

它的表现和CSS上的right类似，但注意在React Native上只能使用逻辑像素值（数字单位），而不能使用百分比、em或是任何其他单位。

访问https://developer.mozilla.org/en-US/docs/Web/CSS/right来进一步了解right是如何影响布局的。

top number

top值是指将本组件定位到距离顶部多少个逻辑像素（顶部的定义取决于position属性）。

它的表现和CSS上的top类似，但注意在React Native上只能使用逻辑像素值（数字单位），而不能使用百分比、em或是任何其他单位。

访问https://developer.mozilla.org/en-US/docs/Web/CSS/top来进一步了解top是如何影响布局的。

width number

width用于设置组件的宽度。

It works similarly to width in CSS, but in React Native you must use logical pixel units, rather than percents, ems, or any of that.访问https://developer.mozilla.org/en-US/docs/Web/CSS/width来进一步了解。

zIndex number

zIndex controls which components display on top of others. Normally, you don't use zIndex. Components render according to their order in the document tree, so later components draw over earlier ones. zIndex may be useful if you have animations or custom modal interfaces where you don't want this behavior.

It works like the CSS z-index property - components with a larger zIndex will render on top. Think of the z-direction like it's pointing from the phone into your eyeball.访问https://developer.mozilla.org/en-US/docs/Web/CSS/z-index 来进一步了解
