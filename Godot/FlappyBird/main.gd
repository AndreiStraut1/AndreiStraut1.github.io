extends Node2D

var started = false

func _physics_process(delta):
	if Input.is_action_just_pressed("flap"):
		started = true

func _on_bird_game_over():
	get_tree().paused = true

func spawn_pipes():
	var new_pipe = preload("res://pipes.tscn").instantiate()
	%PathFollow2D.progress_ratio = randf()
	new_pipe.global_position = %PathFollow2D.global_position
	add_child(new_pipe)


func _on_timer_timeout():
	if started:
		spawn_pipes()
