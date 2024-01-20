from base import *

model.restore('model_trial-10000.pt', verbose=1)

def predict(x):
    prediction = model.predict(torch.tensor([x]))
    return prediction




