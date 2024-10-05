extends CanvasLayer
var points = 0

func _on_bird_score_up():
	points += 1
	%Label.text = "%d" % points
