# IF YOU WANT TO TEST THE DETECTION MODEL
---

## PREREQUISITES

Make sure you have **Python 3.8+** installed on your system before proceeding.
```powershell
# Check if you have python installed
# Put this on your terminal (cmd, powershell)
python --version
```

---

## QUICK SETUP

### Step 1: Set Up the Virtual Environment

Open your terminal (PowerShell for Windows) and run:

```powershell
# 1. Create a local virtual environment
python -m venv .venv

# 2. Activate the virtual environment
.\.venv\Scripts\Activate.ps1

# 3. Install required dependencies
pip install -r requirements.txt
```
### Step 2: Run the Test Script

Navigate to the directory containing the test script and execute it:

```powershell
# 1. Target the directory where the script is located
cd test_model

# 2. Run the main test script
python test.py
``` 
---

## CUSTOM TEST IMAGES

Use the following if you want to play around the model

### Option A: Test images one-by-one

```powershell
from ultralytics import YOLO

# Load the trained model
model = YOLO("../test_model/best.pt")

# Predict on a single image
# Change '/non-bio/' to '/bio/' to test biodegradable waste
# Change 'milo.png' to 'fita.png' or any other image in the directory
results = model.predict(
    source="../test_model/test_images/non-bio/milo.png",
    imgsz=640,
    conf=0.25
)

# Display the image with bounding boxes
results[0].show()
```
### Option B: Test the entire folder simultaenously

```powershell
from ultralytics import YOLO

# Load the trained model
model = YOLO("../test_model/best.pt")

# Predict on all images within a target folder
# Change '/non-bio/' to '/bio/' to test biodegradable waste
results = model.predict(
    source="../test_model/test_images/non-bio/",
    imgsz=640,
    conf=0.25
)

# Iterate through and show results
for result in results:
    result.show()
```