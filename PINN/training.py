from base import *

losshistory, train_state = model.train(iterations=20000)

model.save("model_trial")
dde.saveplot(losshistory, train_state, issave=True, isplot=True)