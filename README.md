# CS 126 FinalProject
## Drawing Application Implementation

1. Project Description             
This drawing application has the following features:
* *drawing* - a user can draw an image of their choice (using the left mouse button), and also 
erase (using the right mouse button)
* *color* - using the color slider, the user can change the color they are drawing in, according
to the amount of red, green, blue, and alpha present in the color
* *manipulate* - the user can manipulate the drawing using the buttons on the right, including
flipping vertically and horizontally, rotating the image, and shifting it in all directions
* *save and open* - the user can save and open their drawings using the text field and the corresponding
buttons - the user just needs to type the name of the file they would like to save as/open in the text
field and click the button of the task they would like to complete

2. Application Loop          
The application is controlled by open frameworks. The main drawing application extends ofBaseApp, 
the base open frameworks application. 
* The main event loop is composed of:
    * *draw()* - which draws the background image and draws the loaded beginning image.
    * *mousePressed()* and *mouseDragged()* - which interprets and edits the drawing and the 
    saved current 2D vector

3. Libraries       
The drawing application uses the following libraries:
* *ofxGUI* - provides usage of buttons and panels
* *ofColor* - which allows the user to use as many colors as they choose in the drawing and 
provides an object for the color values to be stored into
* *ofxInputField* - which allows the user to enter in the name of the file they would like to
open/save as when saving or opening their drawing
