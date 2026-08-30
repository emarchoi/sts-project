YOLO Model Testing

This guide explains how to set up the local environment and test the trained YOLO model using individual images or multiple images at once.

1. Set Up the Environment
Create a virtual environment
python -m venv .venv

Activate the virtual environment

Windows PowerShell:

.\.venv\Scripts\Activate.ps1

Install dependencies
pip install -r requirements.txt

2. Run the Test Script

Navigate to the test_model directory:

cd test_model


Run the test script:

python test.py

3. Test One Waste Image

To test a single waste image, use:

from ultralytics import YOLO

model = YOLO("../test_model/best.pt")

results = model.predict(
    source="../test_model/test_images/non-bio/milo.png",
    imgsz=640,
    conf=0.25
)

results[0].show()

Test a Different Waste Category

The test images are separated into:

test_images/
├── bio/
└── non-bio/


To test biodegradable waste, change:

../test_model/test_images/non-bio/


to:

../test_model/test_images/bio/

Test a Different Image

Change the image filename in the source parameter.

For example:

source="../test_model/test_images/non-bio/fita.png"


You can replace fita.png with any other image in the directory.

4. Test Multiple Images

To test all images inside a directory simultaneously:

from ultralytics import YOLO

model = YOLO("../test_model/best.pt")

results = model.predict(
    source="../test_model/test_images/non-bio/",
    imgsz=640,
    conf=0.25
)

for result in results:
    result.show()


To test biodegradable waste instead:

results = model.predict(
    source="../test_model/test_images/bio/",
    imgsz=640,
    conf=0.25
)

5. Model Configuration

The trained model is located at:

test_model/best.pt


The prediction configuration is:

Parameter	Value	Description
imgsz	640	Image size used during inference
conf	0.25	Minimum confidence threshold
source	—	Image or directory to test
Confidence Threshold

The default confidence threshold is:

conf=0.25


This means detections below 25% confidence are ignored.

You can adjust the value depending on how strict you want the detection to be:

conf=0.50


or:

conf=0.10

Project Structure
.
├── .venv/
├── requirements.txt
├── test_model/
│   ├── best.pt
│   ├── test.py
│   └── test_images/
│       ├── bio/
│       └── non-bio/
└── README.md

Quick Start

After setting up the environment:

cd test_model
python test.py


For custom testing, modify the source path in the Python script to point to the image or directory you want to test.
