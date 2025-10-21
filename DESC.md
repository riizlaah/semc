# Description/Info about current goal

## MVP : Render a text that change each time

Structure:
1. Core
    - Node
        - Name (unique from siblings)
        - Parent
        - Child Management (add/remove/get(by index or name)/get count child)
        - Events (update, physics update, ready, enter_tree, exit_tree, destroyed)
    - Window
        - Title
        - Size
        - Resizeable or not
    - Viewport
        - Responsive mode: no-scale, scale to window, cropped/extended with color(black)
        - Render the scene (searching the camera first, if not found render only the core)
        - Only render node that visible in the viewport
    - ViewportItem
        - Parent of all 2d node
        - Transform (position, scale, rotation)
        - if scale(x or y) >= -1 then its flipped

    - Text
        - Render text
        - Font size & color
        - Font loading
        - Transform
        - Text outline(color & width)
    - ShapeRenderer
        - Shape types: box(width, height), circle(radius), triangle(base,height), capsule(height, radius)
        - Shape color
        - Shape outline(color & width)

