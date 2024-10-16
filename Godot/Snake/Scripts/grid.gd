extends Node2D

func _draw() -> void:
	# draw background
	draw_rect(Rect2(0, 0, Game.GRID_SIZE.x, Game.GRID_SIZE.y), Colors.WHITE)
	
	# draw vertical lines
	for i in Game.CELLS_AMOUNT.x:
		var from := Vector2(i * Game.CELL_SIZE.x, 0)
		var to := Vector2(from.x, Game.GRID_SIZE.y)
		draw_line(from, to, Colors.GRAY)
	
	# draw horizontal lines
	for i in Game.CELLS_AMOUNT.y:
		var from := Vector2(0, i * Game.CELL_SIZE.y)
		var to := Vector2(Game.GRID_SIZE.x, from.y)
		draw_line(from, to, Colors.GRAY)
