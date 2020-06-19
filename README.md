## Simple Application
CmakeLists.txt --> How to build the project and create executable

hello_world.cxx --> Source code

README.md --> Documentation in markdown format

.gitignore --> Files that should not be pushed to git basically *.o, build etc

## Using VS code
```
cd ~\Sources
git clone https://github.com/deepakk87/msl.git
```

Install the following plugin
```
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension wayou.vscode-todo-highlight
```

## Open in vs code
File -> Open Folder -> ~/Sources/msl

Press F7 to build

Press debug/run button at the bottom to run/debug

## Detailed Documentation (Cmake with vs code)
Help here https://vector-of-bool.github.io/docs/vscode-cmake-tools/

How to build
https://vector-of-bool.github.io/docs/vscode-cmake-tools/building.html

How to debug and run
https://vector-of-bool.github.io/docs/vscode-cmake-tools/debugging.html
## How to use git
`git status` <--- Show the list of files which are modified in Red color, Green color one are those which are staged to be commited

`git add filename` <-- Moves the files from red to green so that they can be committed

`git commit -m "commit message like this is the solution to ppp chapter 5 exercise 1"`  <-- Commit the files as single commit with a meaningful message

`git push origin master` <-- Push the files to git so that everyone can see and modify

`git pull --rebase` <-- If push fails do this and then push again

## List of interesting commits
* Simple Hello World application using cmake
https://github.com/deepakk87/msl/commit/20d734dd192d948a49a18b50221db2897375ceb1

* Adding gtest tests with cmake
https://github.com/deepakk87/msl/commit/7d88fa17ceb4f47285f943a4d07b801f61960c9b


