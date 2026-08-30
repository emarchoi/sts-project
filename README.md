# IF YOU WANT TO TEST THE DETECTION MODEL

Follow these instructions to set up your local environment and run inference tests using the trained YOLO model (`best.pt`).

---

## PREREQUISITES

Make sure you have **Python 3.8+** installed on your system before proceeding.

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
