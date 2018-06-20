# CS 126 FinalProject

**WEEK 1**
  * As I have two midterms this week, I haven't been able to work on the actual code this week, but I have
	thought more about how I want to accomplish the goals of this assignment. In order to be able to save the
	user's drawings, I want to divide the workspace into a grid, so it looks like the user is drawing with a 
	square brush. This will then be saved into a text file with the name of an image file at the top, if the 
	user chose to have a background image or not.
* This week, I mainly worked on the functionality, by making my manipulation functions for the function drawn. Next week, I hope to have the visual portion working.
* In addition to this, I found a cool library I'd like to use for changing colors, called [ofxColorPicker](https://github.com/julapy/ofxColorPicker).
	It gives an easy way to choose from all the different colors available for drawing. It is also another outside
	library.
    
**WEEK 2**
  * I have decided I will not be using the library I mentioned above as I found an example of a color picker that I want in the examples folder of the openFrameworks folder.
  * I'm currently looking for a way for a window to pop up to save a file and open a file for my functionality of saving and opening files. I think this will probably be my outside library.
  * I've gotten the visual part to work. The hardest part for me was figuring out the buttons. There wasn't much information online and I was pretty confused for a long time. However, I looked at some examples and figured out how to make my buttons work. My flip methods currently have an out of bounds error and I'm still trying to figure out how to save my drawing.
  
**WEEK 3**
  * I have not been able to find a library that will open File Explorer so I think I have figured out another way to save and open files. I will be using the external library [ofxInputField](https://github.com/fx-lange/ofxInputField) to have the user type the name of the file they would like to save as/open. I will then have buttons to save and open as the user wishes to do.
  * My error in my flip methods was quite minor as my new array wasn't the full size before I tried to access specific elements in it.
  * While trying to code my file saver/opener, I had a lot of trouble as my file wouldn't write the right numbers that I wanted to use to store the values. After many hours of frustration, I figured out that I needed to use "std::to_string" to add numerical values to a string so that the numbers don't add to each other while I am trying to concatenate them. Now that I have figured that out, I am done with all the features of my project that I set out to achieve. 
  * My last task is to clean up magic numbers in the code by creating a constant class or a constant in each class as the only constant I have is the size of the array/the number of boxes in the drawing.
    