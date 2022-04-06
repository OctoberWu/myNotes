### How we find out the messageing system.

DoE:
Running a logging core with DB R/W operations.

Running a program to create 10 connections with 10 request/s each as pressure.

Inference:
DB Busy → request fail/timeout → congestion [websocket be influenced as well] → low update rate → UI laggy

Treatment:
Isolate DB R/W operation individually.