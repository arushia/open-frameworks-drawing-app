# Project Proposal

For my final project, I plan to create a drawing application that allows
a user to draw on the screen with different colors, create shapes, rotate 
and flip their images, and ultimately save these cool drawings!

In order to complete this, I will be using openFrameworks libraries for this project.
  * I plan to use the **graphics** library heavily. 
    - For example, **ofPolyline** will come in extremely helpful as it how the mouse will draw 
    the image from the user.
    - Another class that will be helpful is the **ofGraphics** class. It has methods to draw shapes 
    and change the background, which are other cool features I definitely want to explore.
    - I also would use **ofPixels**, as it has a *getColor()* function that I could use if I am able
    to implement a color chooser.
    
 * In order for my project to use different colors and for the user to draw with different colors
 I would use the **types** library.
    - The **ofColor** class would be extremely necessary as it is the class that contains all the 
    different colors of the rainbow.
    
 * In order to have a windowed application, I will definitely be using the **app** library or the 
 **ofxGUI** add-on.
 
 * In order to be able to rotate the images, I hope to store them in a 2D vector or a matrix. For 
 this feature, I would either use the **utils** library.
    - In the **utils** library, I would possibly use **ofMatrix** class as it has *rotate()* and *flip()* 
    functions that would be extremely useful.
    - I would also use this 2D vector feature to save the images created to text files to be able to save
    and load them.
    
 * In order to intake when the user clicks and unclicks, I would use the **events** library, which has 
 features such as the *mouseMoved* method and all other kinds of *EventListeners*.
    - This is basically what allows the mouse to draw.
    

    
    
