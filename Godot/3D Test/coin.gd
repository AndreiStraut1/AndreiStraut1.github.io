extends Area3D

const ROT_SPEED = 2 # number of degrees the coin rotates every frame

func _physics_process(delta):
	rotate_y(deg_to_rad(ROT_SPEED))



func _on_body_entered(body):
	queue_free()
