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
