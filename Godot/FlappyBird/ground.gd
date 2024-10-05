extends CharacterBody2D

var speed = 250
var direction = Vector2(-1.0, 0.0)
var start_pos = 864

func _physics_process(delta):
	velocity = direction * speed
	move_and_slide()


func _on_area_2d_body_entered(body):
	position.x = start_pos
