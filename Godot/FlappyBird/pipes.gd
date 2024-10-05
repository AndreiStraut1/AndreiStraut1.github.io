extends Node2D

var speed = 250

func _physics_process(delta):
	position.x -= speed * delta


func _on_border_body_entered(body):
	queue_free()
