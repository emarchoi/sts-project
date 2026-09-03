from ultralytics import YOLO

model = YOLO(
    "../test_model/best.pt"
)

results = model.predict(
    source="../test_model/test_images/non-bio/milo.png",
    imgsz=640,
    conf=0.40
)

results[0].show()




