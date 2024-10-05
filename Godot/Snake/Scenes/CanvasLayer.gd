extends CanvasLayer
var points = 0

func _on_spawner_food_score_up():
	points += 1
	%Score.text = "%d" % points
