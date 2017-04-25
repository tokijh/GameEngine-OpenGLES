//
//  ViewController.swift
//  GameEngine OpenGLES
//
//  Created by 윤중현 on 2017. 4. 25..
//  Copyright © 2017년 윤중현. All rights reserved.
//

import GLKit

class ViewController: GLKViewController {

    var gameView: GLKView!
    
    var gameEngine: GameEngineWrapper!
    
    var isCreated: Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        initGameView()
    }
    
    func initGameEngine() {
        gameEngine = GameEngineWrapper()
        
        gameEngine.onCreated()
        setDeviceWindow()
    }
    
    func initGameView() {
        gameView = self.view as! GLKView!
        gameView.context = EAGLContext(api: .openGLES3)
    }
    
    func setDeviceWindow() {
        let bounds = UIScreen.main.bounds
        let width = bounds.size.width
        let height = bounds.size.height
        gameEngine.onChanged(Int32(width), Int32(height))
    }
    
    override func glkView(_ view: GLKView, drawIn rect: CGRect) {
        if !isCreated {
            initGameEngine()
            isCreated = true
        }
        gameEngine.onDraw()
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        // UIDevice.current.orientation.isLandscape // 화면 가로 세로 확인
        if gameEngine != nil {
            setDeviceWindow()
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        if gameEngine != nil {
            gameEngine.onDestroy()
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

