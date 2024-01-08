.global reset
reset:
	ldr sp, =top_of_stack
	bl main
stop: b stop
