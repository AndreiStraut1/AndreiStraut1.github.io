extends Node

const GRID_SIZE := Vector2(800, 480)
const CELL_SIZE := Vector2(32, 32)


const CELLS_AMOUNT := Vector2(GRID_SIZE.x / CELL_SIZE.x, GRID_SIZE.y / CELL_SIZE.y)


func _input(event):
	if event.is_action_pressed("restart"):
		get_tree().reload_current_scene()
