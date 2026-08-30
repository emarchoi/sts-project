from ultralytics import YOLO
import cv2

# Load the trained YOLO model
model = YOLO("../test_model/best.pt")

# Display the class names from the trained model
print("Model classes:", model.names)

# Open the default webcam
cap = cv2.VideoCapture(0)

# Check if the webcam opened successfully
if not cap.isOpened():
    print("ERROR: Could not open webcam.")
    exit()

print("Camera started.")
print("Press Q to quit.")

# Continuously read frames from the webcam
while True:
    success, frame = cap.read()

    # Check if the frame was read successfully
    if not success:
        print("ERROR: Could not read frame.")
        break

    # Run the YOLO model on the current frame
    results = model(
        frame,
        imgsz=640,
        conf=0.25,
        verbose=False
    )

    # Draw the detected objects and labels on the frame
    annotated_frame = results[0].plot()

    # Display the annotated frame
    cv2.imshow(
        "Waste Classification",
        annotated_frame
    )

    # Press Q to exit the program
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# Release the webcam
cap.release()

# Close all OpenCV windows
cv2.destroyAllWindows()

print("Camera closed.")