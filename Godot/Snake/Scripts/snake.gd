class_name Snake
extends Node2D

var head := Minisnake.new()
var minisnakes := [] as Array[Minisnake]

var curr_direction := Vector2.RIGHT 
var next_direction := Vector2.RIGHT 

var tween_move: Tween

func _ready():
	head.size = Game.CELL_SIZE
	head.color = Colors.BLUE_DARK
	minisnakes.push_front(head)
	
	tween_move = create_tween().set_loops()
	tween_move.tween_callback(move).set_delay(.15)

func _physics_process(delta):
	queue_redraw()


func _draw():
	for minisnake in minisnakes:
		draw_rect(minisnake.get_rect(), minisnake.color)

func _input(event):
	if event.is_action_pressed("move_left") and curr_direction != Vector2.RIGHT:
		next_direction = Vector2.LEFT
	if event.is_action_pressed("move_right") and curr_direction != Vector2.LEFT:
		next_direction = Vector2.RIGHT
	if event.is_action_pressed("move_up") and curr_direction != Vector2.DOWN:
		next_direction = Vector2.UP
	if event.is_action_pressed("move_down") and curr_direction != Vector2.UP:
		next_direction = Vector2.DOWN
	
	# for testing
	if event.is_action_pressed("grow"):
		grow()

func move() -> void:
	curr_direction = next_direction
	var next_position = head.curr_position + (curr_direction * Game.CELL_SIZE)
	next_position.x = fposmod(next_position.x, Game.GRID_SIZE.x)
	next_position.y = fposmod(next_position.y, Game.GRID_SIZE.y)
	head.curr_position = next_position
	
	# move other minisnakes
	for i in range(1, minisnakes.size()):
		minisnakes[i].curr_position = minisnakes[i-1].prev_position
	
	for i in range(1, minisnakes.size()):
		if head.get_rect().intersects(minisnakes[i].get_rect()):
			%GameOverLayer.visible = true
			tween_move.kill()

func grow() -> void:
	var minisnake := Minisnake.new()
	var last_minisnake := minisnakes.back() as Minisnake
	
	minisnake.curr_position = last_minisnake.curr_position
	minisnake.color = Colors.BLUE
	minisnake.size = Game.CELL_SIZE
	minisnakes.push_back(minisnake)
