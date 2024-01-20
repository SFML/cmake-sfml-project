"""Backend supported: tensorflow.compat.v1, tensorflow, pytorch, jax, paddle"""
import deepxde as dde
import numpy as np
import torch


def func(x):
    """
    x: array_like, N x D_in
    y: array_like, N x D_out
    """
    return -x


geom = dde.geometry.Interval(-100, 100)
num_train = 1000
num_test = 1000
data = dde.data.Function(geom, func, num_train, num_test, online = True, train_distribution = "LHS")

activation = "tanh"
initializer = "Glorot uniform"
net = dde.nn.FNN([1] + [20] * 3 + [1], activation, initializer)

model = dde.Model(data, net)
model.compile("adam", lr=0.001, metrics=["l2 relative error"])