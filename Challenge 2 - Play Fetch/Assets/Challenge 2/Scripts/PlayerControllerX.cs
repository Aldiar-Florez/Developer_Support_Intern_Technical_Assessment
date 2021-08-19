using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControllerX : MonoBehaviour
{
    public GameObject dogPrefab;
    private float delay = 3.0f;
    private float press;

    // Update is called once per frame
    void Update()
    {
        // On spacebar press, send dog
        if (Input.GetKeyDown(KeyCode.Space) && Time.time>press)
        {
            Instantiate(dogPrefab, transform.position, dogPrefab.transform.rotation);
            press = Time.time + delay;
        }
    }

}
