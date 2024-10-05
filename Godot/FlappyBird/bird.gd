extends CharacterBody2D

var gravity = 150
var speed = -5000
@onready var animation = $AnimatedSprite2D
signal game_over
var started = false
signal scoreUp

func _ready():
	animation.play("flying")

func _physics_process(delta):
	if Input.is_action_just_pressed("flap"):
		started = true
		
	if started:
		var direction = Vector2(0.0, -1.0)
		velocity = lerp(velocity, Vector2(0, gravity), 0.2)
		gravity += 10
		move_and_slide()
		rotation = lerp_angle(rotation, PI/2, 1.0 * delta)
	
	if Input.is_action_just_pressed("flap"):
		velocity = lerp(velocity, Vector2(0, speed), 0.2)
		move_and_slide()
		rotation = -20
		gravity = 150
	
	if %HurtBox.get_overlapping_bodies() or %HurtBox.get_overlapping_areas():
		game_over.emit()


func _on_collect_box_area_entered(area):
	scoreUp.emit()
