package ru.techno;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;

public class GameModel extends ApplicationAdapter {
	SpriteBatch batch;
	Texture bird;
	
	@Override
	public void create () {
		batch = new SpriteBatch();
		bird = new Texture("drawable/bluebird_downflap.png");

	}

	@Override
	public void render () {
		Gdx.gl.glClearColor(1, 0, 0, 1);
		Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
		batch.begin();
		batch.draw(bird, 200, 200);
		batch.end();
	}
	
	@Override
	public void dispose () {
		batch.dispose();
		bird.dispose();
	}
}
