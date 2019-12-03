import matplotlib #TODO: Install matplotlib using pip
import sys
import cv
# Extra credit requires numpy. Uncomment this line and install it if you need to.
#import numpy as np

# Store command line arguments in variables
filename = sys.argv[1]
type = sys.argv[2]

# Open the image file
data = cv2.imread('../' + filename)
for x in range(dimensions[0]):
    for y in range(dimensions[1]):
        if type == 'bar':
            #TODO: Create bar graph.
        elif type == 'line':
            #TODO: Create bar graph.
        elif type == 'scatter':
            #TODO: Create bar graph.



# Infinite loop to keep the windows open until the escape key is pressed.
while True:
    k = cv2.waitKey(1)
    if k == 27:
        cv2.destroyAllWindows()
        exit()
