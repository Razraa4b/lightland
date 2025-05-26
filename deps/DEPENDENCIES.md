# ☄Project dependencies

In order to build the project into a working version, you need to bind some dependencies.

## Installing

Install the submodules specified in .gitmodules into the deps folder. Next you need to build these submodules, go to the submodule folder and run the following command for each submodule:
```bash
cmake . && cmake --build .
```
Great, now the dependencies are ready to go
