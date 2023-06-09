## README.md
# f446_RL_template
`This is my completed NUCLEO-F446RE programming template. Note that the goal of this project was
to create a template for programming the board on a register level, AKA no HAL drivers. The editor
I am using is VSCode.`

It is for Windows and can be used to program the STM32F446RETx using a Makefile and ST toolchain.
In this project, I have included a header and source file titled "blink." These are used to show
where the additional headers and sources may be added. The sources must be included in the Makefile
section titled "C sources." The blink.c is shown there and can be used as an example of where to
add more.

To build program, clean build folder, and flash the controller, there are three build tasks. 
These can be found in the tasks.json file. They are used by opening the command palette (ctrl+shift+p), 
typing Tasks: Run Build Task, selecting this option, and then choosing one of the three listed options.
Alternatively, I believe the command to open the build tasks selection is ctrl+shift+b.

The flash is done using st-flash (ST-Link). Additionally there is a debug launch in launch.json.
This can be launched in the run&debug menu of VSCode.
